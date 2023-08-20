// helper fn to avoid defining non-existent keys for 36 key variation
#define LAYOUT_ximi36( \
  K01, K02, K03, K04, K05, K35, K34, K33, K32, K31, \
  K11, K12, K13, K14, K15, K45, K44, K43, K42, K41, \
  K21, K22, K23, K24, K25, K55, K54, K53, K52, K51, \
            K06, K16, K26, K56, K46, K36 \
  ) \
  { \
    { ___, K01, K02, K03, K04, K05, K06, ___ }, \
    { ___, K11, K12, K13, K14, K15, K16, ___ }, \
    { ___, K21, K22, K23, K24, K25, K26, ___ }, \
    { ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { ___, K31, K32, K33, K34, K35, K36, KC_VOLD }, \
    { ___, K41, K42, K43, K44, K45, K46, KC_MUTE }, \
    { ___, K51, K52, K53, K54, K55, K56, KC_VOLU }, \
    { ___, ___, ___, ___, ___, ___, ___, ___ } \
  }
