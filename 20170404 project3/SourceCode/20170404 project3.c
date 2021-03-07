task main()
{
	int num[] = {2,0,1,7,0,4,0,4};	//num <- student number array
	int hab, i=0, tcgf[8];					//hab <- integer, i <- for while loop, tcgf <- saving true or false array
	float gob, nanum;								//gob, nanum <- float considering rational number

	hab = num[6]+num[7];						// hab, gob, nanum <- calculating
	gob = hab*num[5];
	nanum = gob/num[3];

	for(i=0;i<=7;i++){										//putting 1 or 0 in tcgf array, using for loop
		tcgf[i] = num[0]<num[i];
	}

	displayBigTextLine(1,"%d+%d = %d", num[6], num[7], hab);				//hab = 4
	displayBigTextLine(3,"%d*%d = %d", hab, num[5], gob);							//gob = 16
	displayBigTextLine(5,"%d/%d = %f",gob, num[3], nanum);							//nanum = 2.2857142857
	displayBigTextLine(7,"%d%d%d%d%d%d%d%d", tcgf[0], tcgf[1], tcgf[2], tcgf[3], tcgf[4], tcgf[5], tcgf[6], tcgf[7]);
	sleep(150000);
}
