#pragma once

#include "../plugin.h"

static CLAP_CONSTEXPR const char CLAP_EXT_TIMER_SUPPORT[] = "clap.timer-support";

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, CLAP_ALIGN)

typedef struct clap_plugin_timer_support {
   // [main-thread]
   void (*on_timer)(const clap_plugin_t *plugin, clap_id timer_id);
} clap_plugin_timer_support_t;

typedef struct clap_host_timer_support {
   // Registers a periodic timer.
   // The host may adjust the period if it is under a certain threshold.
   // 30 Hz should be allowed.
   // [main-thread]
   bool (*register_timer)(const clap_host_t *host, uint32_t period_ms, clap_id *timer_id);

   // [main-thread]
   bool (*unregister_timer)(const clap_host_t *host, clap_id timer_id);
} clap_host_timer_support_t;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif