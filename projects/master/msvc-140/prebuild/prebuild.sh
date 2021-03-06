#reboot shell on system update
if [ $UPDATE_SYSTEM == true ]
then
	pacman --noconfirm --needed -Sy bash pacman pacman-mirrors msys2-runtime
	exit
else
	pacman --noconfirm --needed -Su
	pacman --noconfirm --needed -S make wget tar rsync
	pacman --noconfirm --needed -S autoconf autogen automake
	pacman --noconfirm --needed -S icon-naming-utils intltool itstool unzip p7zip bison
fi

echo $COMPRESSED_DIR_M
echo $PROJECTS_DIR_M

#extraction will fail if destination directory can't be created
if [[ -z $COMPRESSED_DIR_M ]]
then
	echo destination directory not set
	read temp
	exit
fi

if [[ ! -d $COMPRESSED_DIR_M ]]
then
	mkdir --parents $COMPRESSED_DIR_M
fi

cd $COMPRESSED_DIR_M

wget --quiet --show-progress --no-clobber -i $PROJECTS_DIR_M/master/msvc-140/prebuild/package-list.txt

if [[ -n `find ./*.xz` ]]
then
	for f in *.xz
		do echo extracting $f
		tar --skip-old-files --exclude-from=$PROJECTS_DIR_M/master/msvc-140/prebuild/tar-exclude-list.txt -xf $f -C $PROJECTS_DIR_M
	done
fi

if [[ -n `find ./*.gz` ]]
then
	for f in *.gz
		do echo extracting $f
		tar --skip-old-files --exclude-from=$PROJECTS_DIR_M/master/msvc-140/prebuild/tar-exclude-list.txt -xf $f -C $PROJECTS_DIR_M
	done
fi

if [[ -n `find ./*.bz2` ]]
then
	for f in *.bz2
		do echo extracting $f
		tar --skip-old-files --exclude-from=$PROJECTS_DIR_M/master/msvc-140/prebuild/tar-exclude-list.txt  -xf $f -C $PROJECTS_DIR_M
	done
fi

#zip files should be "fixed"
if [[ -n `find ./jasper*.zip` ]]
then
	echo extracting jasper
	unzip -n -qq jasper* -x $(cat $PROJECTS_DIR_M/master/msvc-140/prebuild/unzip-exclude-list.txt) -d $PROJECTS_DIR_M
fi

if [[ -n `find ./icu*.zip` ]]
then
	echo extracting icu
	unzip -n -qq icu* -x $(cat $PROJECTS_DIR_M/master/msvc-140/prebuild/unzip-exclude-list.txt) -d $PROJECTS_DIR_M
#	echo renaming icu
	#if old icu directory exist mv will fail, so performing rsync followed by rm
	#also `find ./ -name icu-*` is significant here
#	if [[ -n `find ./ -name icu-*` ]]
#	then
#		rsync --remove-source-files --recursive $PROJECTS_DIR_M/icu $PROJECTS_DIR_M/icu-56.1
#		rm --recursive --force icu
#	else
#		mv $PROJECTS_DIR_M/icu $PROJECTS_DIR_M/icu-56.1
#	fi
fi

if [[ -n `find ./dirent*.zip` ]]
then
	echo extracting dirent
	unzip -n -qq dirent* -x $(cat $PROJECTS_DIR_M/master/msvc-140/prebuild/unzip-exclude-list.txt) -d $PROJECTS_DIR_M/dirent-1.21
fi

if [[ -n `find ./readline*.zip` ]]
then
	echo extracting readline
	unzip -n -qq readline* -x $(cat $PROJECTS_DIR_M/master/msvc-140/prebuild/unzip-exclude-list.txt) -d $PROJECTS_DIR_M/readline-5.0-1
fi

if [[ -n `find ./cryptopp*.zip` ]]
then
	echo extracting cryptopp
	unzip -n -qq cryptopp* -x $(cat $PROJECTS_DIR_M/master/msvc-140/prebuild/unzip-exclude-list.txt) -d $PROJECTS_DIR_M/cryptopp-5.6.3
fi

#7.z files usually do not have root directory
if [[ -n `find ./*.7z` ]]
then
	echo WARNING: there are 7z files, 7z files are not supported
fi

echo All done! press any key to exit
read x
