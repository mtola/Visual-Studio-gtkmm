if not exist $(FEATURES_DIR)$(Configuration).FEATURES del $(FEATURES_DIR)cairo-features.h
echo /* Generated by VS Project File  Do not edit. */ > $(FEATURES_DIR)cairo-features.h
echo #ifndef CAIRO_FEATURES_H >> $(FEATURES_DIR)cairo-features.h
echo #define CAIRO_FEATURES_H >> $(FEATURES_DIR)cairo-features.h
type $(FEATURES_DIR)$(Configuration).FEATURES >> $(FEATURES_DIR)cairo-features.h
echo #endif >> $(FEATURES_DIR)cairo-features.h