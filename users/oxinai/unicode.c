#include "unicode.h"
#include "oxinai.h"

bool process_record_unicode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case lcbr:
             if (record->event.pressed) send_unicode_string("｢");
             return false;
        case rcbr:
             if (record->event.pressed) send_unicode_string("｣");
             return false;
        case disapoint:
             if (record->even.pressed) send_unicode_string("��");
    }
    return true;
};
