#include <stdio.h>
#include <math.h>

int main() {
    const int ac_kwh = 261, fan_kwh = 12, tv_kwh = 27, ref_kwh = 117;
    int ac_qty, fan_qty, tv_qty, ref_qty, ac_hr, fan_hr, tv_hr, ref_hr;

    printf("Description\tQty\tHrs/Day\n");
    printf("Aircon\t"); scanf("%d %d", &ac_qty, &ac_hr);
    printf("Fan\t"); scanf("%d %d", &fan_qty, &fan_hr);
    printf("TV\t"); scanf("%d %d", &tv_qty, &tv_hr);
    printf("Refrigerator\t"); scanf("%d %d", &ref_qty, &ref_hr);

    int totalUsage = (ac_qty*ac_hr*30) + (fan_qty*fan_hr*30) + (tv_qty*tv_hr*30) + (ref_qty*ref_hr*30);
    puts("\n");

    printf("Summary:\n");
    printf("Description\tQuantity\tHrs/Day\n");
    printf("Aircon\t\t%d\t\t%d\n", ac_qty, ac_hr);
    printf("Fan\t\t%d\t\t%d\n", fan_qty, fan_hr);
    printf("TV\t\t%d\t\t%d\n", tv_qty, tv_hr);
    printf("Refrigerator\t%d\t\t%d\n", ref_qty, ref_hr);
    
    printf("\nTotal Usage (hrs): \t\t%d\n", totalUsage);

    int totalConsumption = ((ac_qty*ac_hr*ac_kwh) * 30) + ((fan_qty*fan_hr*fan_kwh) * 30) + ((tv_qty*tv_hr*tv_kwh) * 30) + ((ref_qty*ref_hr*ref_kwh) * 30);
    printf("Total Consumption (kwh): \t%d\n", totalConsumption);
    double exceedCharges = ((totalConsumption-100000) * 0.03f) + (100000.00f * 0.05f);
    printf("Total Charges:\t\tPesos\t%.2f\n", (totalConsumption >= 100000) ? exceedCharges : totalConsumption*0.05f);
}