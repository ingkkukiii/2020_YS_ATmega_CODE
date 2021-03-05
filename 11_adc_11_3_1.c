
/*
char str[50];
extern unsigned char error;
extern unsigned char checksum;

int main()
{
	value humi_val, temp_val;
	float dew_point;
	unsigned int i;

	portOut();
	LCDInit();
	waitBusy();

	s_connectionreset();

	while(1){
		error = 0;
		error += s_measure((unsigned char*) &humi_val.i, &checksum, HUMI);
		error += s_measure((unsigned char*) &temp_val.i, &checksum, TEMP);

		if(error != 0)
			s_connectionreset();
		else
		{
			humi_val.f = (float)humi_val.i;
			temp_val.f = (float)temp_val.i;
			calc_sth11(&humi_val.f, &temp_val.f);
			dew_point = calc_dewpoint(humi_val.f, temp_val.f);

			setPosition(0,0);
			waitBusy();

			dtostrf(temp_val.f, 4, 1, str);
			writeSTR("TP:");
			waitBusy();
			writeSTR(str);
			waitBusy();

			cursorShiftRight();
			waitBusy();

			dtostrf(humi_val.f, 4, 1, str);
			writeSTR("HM:");
			waitBusy();
			writeSTR(str);
			waitBusy();

			setPosition(1,0);
			waitBusy();

			dtostrf(dew_point, 4, 1, str);
			writeSTR("DP:");
			waitBusy();
			writeSTR(str);
			waitBusy();
			}
		}
	return 0;
}
*/
