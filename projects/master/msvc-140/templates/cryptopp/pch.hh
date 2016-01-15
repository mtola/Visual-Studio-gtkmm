#ifndef PCH_HH
#define PCH_HH

// PCH includes
// TODO: modify or add more includes here for faster compilation and intellisense according to your needs

#include <pragma_begin.hh> // disable warnings (to compile own code with W4 flag)

#include <cryptopp\hex.h>
#include <cryptopp\aes.h>
#include <cryptopp\ccm.h>
#include <cryptopp\rsa.h>
#include <cryptopp\modes.h>
#include <cryptopp\files.h>
#include <cryptopp\base64.h>
#include <cryptopp\pubkey.h>
#include <cryptopp\filters.h>

#include <pragma_end.hh> // enable warnings

#endif // !PCH_HH