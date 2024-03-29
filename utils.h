
#define VER "2403.22"
#define CONFIG_FILE "/data/adb/modules/JZTOOLS/config.txt"
#define IS_CHARGING_USB "/sys/class/power_supply/usb/online"
#define IS_CHARGING_WIRELESS "/sys/class/power_supply/wireless/online"
#define IS_CHARGING_WIRELESS "/sys/class/power_supply/wireless/online"

#define r 'r'
#define w 'w'

#define MAX_LINE_LENGTH 255
#define MAX_ENTRIES 100

#define DEBUG 0

#if DEBUG
#define mydebug(fmt, ...) printf("JZTool: %s: " fmt, __func__, ##__VA_ARGS__)
#define POLLINGTIME_REFESH_CONFIG 3 // Secend
#define POLLINGTIME 3
#define POLLINGTIME_ON 3  // Secend
#define POLLINGTIME_OFF 3 // Secend
#else
#define mydebug(fmt, ...) ((void)0)
#define POLLINGTIME_REFESH_CONFIG 15 // Secend
#define POLLINGTIME 10
#define POLLINGTIME_ON 15  // Secend
#define POLLINGTIME_OFF 20 // Secend
#endif

struct configkeyval
{
    char key[MAX_LINE_LENGTH];
    int value;
};

struct config
{
    int batt_limit;
    int battstats_reset; // use command dumpsys batterystats --reset
    int batt_changed;
    int dc_on_bri;
    int dc_en;
    int dc_usb_force;    // force enable dc when usb connected
    int poolingtime;     // pooling times
    int poolingtime_on;  // screen on
    int poolingtime_off; // screen off
};

int file_wr(const char *filepath, const char wr, const int val);
void getcurtime();
int read_config(const char *filename, struct configkeyval *entries);
int do_batt_limit(struct config *params);
int ispluged(struct config *params);
int dc_control(struct config *params);
