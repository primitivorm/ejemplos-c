#include <stdio.h>
#include <string.h>
//#include "gvt.h"
#include "ht.h"

static int tests = 0, fails = 0;
#define test(_s) { printf("#%02d %s ", ++tests, _s); }
#define test_cond(_c) if(_c) printf("\033[0;32mPASSED\033[0;0m\n"); else {printf("\033[0;31mFAILED\033[0;0m\n"); fails++;}
#define expect(_s, _c) { test(_s); test_cond(_c); }

/*void testExtractGvt(char* version, char *imei, char *name, char RS,
                    char date[7], char time[7], char fixable,
                    char latitude[11], char NS,
                    char longitude[13], char WE,
                    char usedBds[3], char usedGps[3], char usedGlonass[3],
                    float hdop, float speed, float course, float altitude, float mileage,
                    char mcc[4], char mnc[3], char lac[5], char cellId[5],
                    char gsmSignal,
                    char digitalInFlags, char digitalOutFlags,
                    short analog1, short analog2, short analog3,
                    float temperature1, float temperature2,
                    // char rfid,         /\* (reserved) RFID *\/ 
                    // char external,     /\* (reserved) external accessories status *\/ 
                    char battery, char alert[25]) /|* char checksum,      /\* (reserved) checksum *\/ 
{
        struct gvtData data;
        char gvtStr[512];
        sprintf(gvtStr, "$%s,%s,%s,%c,%s,%s,%c,%s,%c,%s,%c,%s,%s,%s,%f,%f,%f,%f,%f," // mileage
                "%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%f,%f,,,%d,%s,;!",
                version, imei, name, RS, date, time, fixable, latitude, NS, longitude, WE, usedBds, usedGps, usedGlonass,
                hdop, speed, course, altitude, mileage, mcc, mnc, lac, cellId, gsmSignal, digitalInFlags, digitalOutFlags,
                analog1, analog2, analog3, temperature1, temperature2, battery, alert);

        expect("gvtExtract return true", gvtExtract(gvtStr, &data));

        expect("version", strcmp(data.version, version) == 0);
        expect("imei", strcmp(data.imei, imei) == 0);
        expect("name", strcmp(data.name, name) == 0);
        expect("RS", data.RS == RS);
        expect("date", strcmp(data.date, date) == 0);
        expect("time", strcmp(data.time, time) == 0);
        expect("fixable", data.fixable == fixable);
        expect("latitude", strcmp(data.latitude, latitude) == 0);
        expect("NS", data.NS == NS);
        expect("longitude", strcmp(data.longitude, longitude) == 0);
        expect("WE", data.WE == WE);
        expect("usedBds", strcmp(data.usedBds, usedBds) == 0);
        expect("usedGps", strcmp(data.usedGps, usedGps) == 0);
        expect("usedGlonass", strcmp(data.usedGlonass, usedGlonass) == 0);
        expect("hdop", data.hdop == hdop);
        expect("speed", data.speed == speed);
        expect("course", data.course == course);
        expect("altitude", data.altitude == altitude);
        expect("mileage", data.mileage == mileage);
        expect("mcc", strcmp(data.mcc, mcc) == 0);
        expect("mnc", strcmp(data.mnc, mnc) == 0);
        expect("lac", strcmp(data.lac, lac) == 0);
        expect("cellId", strcmp(data.cellId, cellId) == 0);
        expect("gsmSignal", data.gsmSignal == gsmSignal);
        expect("digitalInFlags", data.digitalInFlags == digitalInFlags);
        expect("digitalOutFlags", data.digitalOutFlags == digitalOutFlags);
        expect("analog1", data.analog1 == analog1);
        expect("analog2", data.analog2 == analog2);
        expect("analog3", data.analog3 == analog3);
        expect("temperature1", data.temperature1 == temperature1);
        expect("temperature2", data.temperature2 == temperature2);
        expect("battery", data.battery == battery);
        expect("alert", strcmp(data.alert, alert) == 0);
}

void testGvt()
{
        testExtractGvt("MGV002", "860719020193193", "DeviceName", 'R',
                       "240214", "104742", 'A', "2238.20471",
                       'N', "11401.97967", 'E', "00", "03", "00", 1.20f,
                       0.462f, 356.23f, 137.9f, 1.5f, "460", "07", "262C",
                       "0F54", 25, 0, 0, 0, 0, 0, 28.5f,
                       28.3f, 100, "Timer");

        testExtractGvt("MGV002", "860719020193360", "DeviceName2", 'S',
                       "240214", "104742", 'A', "2238.20471",
                       'N', "11401.97967", 'E', "00", "03", "00", 1.20f,
                       0.462f, 356.23f, 137.9f, 1.5f, "460", "07", "262C",
                       "0F54", 25, 0, 0, 0, 0, 0, 28.5f,
                       28.3f, 100, "Timer");

        testExtractGvt("MGV002", "860719020193193", "DeviceName3", 'R',
                       "240214", "104742", 'A', "2238.20471",
                       'N', "11401.97967", 'E', "00", "03", "00", 1.20f,
                       0.462f, 356.23f, 137.9f, 1.5f, "460", "07", "262C",
                       "0F54", 25, 0, 0, 0, 0, 0, 28.5f,
                       28.3f, 100, "Timer");

        testExtractGvt("MGV002", "860719020193193", "DeviceName4", 'R',
                       "240214", "104742", 'A', "2238.20471",
                       'N', "11401.97967", 'E', "00", "03", "00", 1.20f,
                       0.462f, 356.23f, 137.9f, 1.5f, "460", "07", "262C",
                       "0F54", 25, 0, 0, 0, 0, 0, 28.5f,
                       28.3f, 100, "Timer");

        testExtractGvt("MGV002", "867714727193193", "DeviceName5", 'R',
                       "240215", "104795", 'A', "2238.20471",
                       'N', "11401.97967", 'E', "00", "03", "00", 1.20f,
                       0.462f, 356.23f, 137.9f, 1.5f, "460", "07", "262C",
                       "0F54", 25, 0, 0, 0, 0, 0, 28.5f,
                       28.3f, 100, "Timer");
}
*/

void testHashtable()
{
        struct hashtable *ht = htCreate(65536);

        htSet(ht, "key1", "inky", strlen("inky") + 1);
        htSet(ht, "key2", "pinky", strlen("pingky") + 1);
        htSet(ht, "key3", "blinky", strlen("blinky") + 1);
        htSet(ht, "key4", "floyd", strlen("floyd") + 1);

        expect("hash key1 is inky", strcmp(htGet(ht, "key1"), "inky") == 0);
        expect("hash key2 is pinky", strcmp(htGet(ht, "key2"), "pinky") == 0);
        expect("hash key3 is blinky", strcmp(htGet(ht, "key3"), "blinky") == 0);
        expect("hash key4 is floyd", strcmp(htGet(ht, "key4"), "floyd") == 0);

        htSet(ht, "key1", "new-inky", strlen("new-inky") + 1);
        htSet(ht, "key2", "new-pinky", strlen("new-pinky") + 1);
        htSet(ht, "key3", "new-blinky", strlen("new-blinky") + 1);
        htSet(ht, "key4", "new-floyd", strlen("new-floyd") + 1);

        expect("hash key1 is new-inky", strcmp(htGet(ht, "key1"), "new-inky") == 0);
        expect("hash key2 is new-pinky", strcmp(htGet(ht, "key2"), "new-pinky") == 0);
        expect("hash key3 is new-blinky", strcmp(htGet(ht, "key3"), "new-blinky") == 0);
        expect("hash key4 is new-floyd", strcmp(htGet(ht, "key4"), "new-floyd") == 0);

        int n = 5;
        htSet(ht, "key5", &n, sizeof(int)); n++;
        htSet(ht, "key6", &n, sizeof(int)); n++;
        htSet(ht, "key7", &n, sizeof(int)); n++;
        htSet(ht, "key8", &n, sizeof(int)); n++;

        expect("hash key5 is 5", *htGet(ht, "key5") == 5);
        expect("hash key6 is 6", *htGet(ht, "key6") == 6);
        expect("hash key7 is 7", *htGet(ht, "key7") == 7);
        expect("hash key8 is 8", *htGet(ht, "key8") == 8);

        n = 50;
        htSet(ht, "key5", &n, sizeof(int)); n++;
        htSet(ht, "key6", &n, sizeof(int)); n++;
        htSet(ht, "key7", &n, sizeof(int)); n++;
        htSet(ht, "key8", &n, sizeof(int)); n++;

        expect("hash key5 is 50", *htGet(ht, "key5") == 50);
        expect("hash key6 is 51", *htGet(ht, "key6") == 51);
        expect("hash key7 is 52", *htGet(ht, "key7") == 52);
        expect("hash key8 is 53", *htGet(ht, "key8") == 53);

        //struct gvtData *data;
        //struct gvtData gvtData;

        //strcpy(gvtData.imei, "IMEI");
        //gvtData.speed = 500.f;
        //htSet(ht, "key9", &gvtData, sizeof(gvtData));

        //strcpy(gvtData.imei, "imei");
        //gvtData.speed = 1000.f;
        //htSet(ht, "key10", &gvtData, sizeof(gvtData));

        //data = (struct gvtData*)htGet(ht, "key9");
        //expect("hash key9 imei is IMEI", strcmp(data->imei, "IMEI") == 0);
        //expect("hash key9 speed is 500.f", data->speed == 500.f);

        //data = (struct gvtData*)htGet(ht, "key10");
        //expect("hash key10 imei is imei", strcmp(data->imei, "imei") == 0);
        //expect("hash key10 speed is 1000.f", data->speed == 1000.f);

        //strcpy(gvtData.imei, "new-IMEI");
        //gvtData.speed = 5000.f;
        //htSet(ht, "key9", &gvtData, sizeof(gvtData));

        //strcpy(gvtData.imei, "new-imei");
        //gvtData.speed = 10000.f;
        //htSet(ht, "key10", &gvtData, sizeof(gvtData));

        //data = (struct gvtData*)htGet(ht, "key9");
        //expect("hash key9 imei is new-IMEI", strcmp(data->imei, "new-IMEI") == 0);
        //expect("hash key9 speed is 5000.f", data->speed == 5000.f);

        //data = (struct gvtData*)htGet(ht, "key10");
        //expect("hash key10 imei is new-imei", strcmp(data->imei, "new-imei") == 0);
        //expect("hash key10 speed is 10000.f", data->speed == 10000.f);
}

int main()
{
        //testGvt();
        testHashtable();

        printf("Tests: %d, F: %d\n", tests, fails);
        return 0;
}
