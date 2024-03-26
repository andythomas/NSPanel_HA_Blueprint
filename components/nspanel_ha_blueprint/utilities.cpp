// utilities.cpp
#include "utilities.h"
#include <cstdint>
#include <cstring>

namespace nspanel_ha_blueprint {

    // Definition and initialization of the global variable
    UtilitiesGroupValues UtilitiesGroups[8] = {
        { "grid", "\0", "\0", 0 },
        { "group01", "\0", "\0", 0 },
        { "group02", "\0", "\0", 0 },
        { "group03", "\0", "\0", 0 },
        { "group04", "\0", "\0", 0 },
        { "group05", "\0", "\0", 0 },
        { "group06", "\0", "\0", 0 },
        { "home", "\0", "\0", 0 }
    };

    uint8_t findUtilitiesGroupIndex(const char* group_id) {
        int low = 0;
        int high = sizeof(UtilitiesGroups) / sizeof(UtilitiesGroups[0]) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmp = strcmp(UtilitiesGroups[mid].group_id, group_id);

            if (cmp < 0) {
                low = mid + 1;
            } else if (cmp > 0) {
                high = mid - 1;
            } else {
                return static_cast<uint8_t>(mid); // Found
            }
        }

        return UINT8_MAX; // Not found
    }

}  // namespace nspanel_ha_blueprint