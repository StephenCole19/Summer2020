//return 1 if yes, else 0
int isFib(int val)
{
	int a=0;
	int b=1;

	if(val==a || val==b)
		return 1;

	int nextNum = a+b;
	while(nextNum<=val)
	{
		if(val==nextNum)
			return 1;
		a=b;
		b=nextNum;
		nextNum=a+b;
	}

	return 0;
}
