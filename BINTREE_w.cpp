#include <stdio.h>
#include <conio.h>
#include <math.h>

#define Number 16

struct D
{
	int value;
	bool create;

};

class B
{
	D d[Number];
	int layer;
public:
	B()
	{
		for(int i=0;i<Number;++i)
		{
			d[i].create=0;
		}
		layer=0;
	}
	int GetValue(int i)
	{
		return d[i].value;
	}
	void AddElem(int c)
	{
		int g=1,k=0;
		while(1)
		{
			if(k*g>Number)
			{
				if(layer<3)
				{
					++layer;
					g=1;
				}
				else
				{
					printf("tree is full\n");
					return;
				}
			}
			k=(Number+1)/pow(2.,layer+1);
			if(d[k*g].create)
			{
				++g;
			}
			else
			{
				d[k*g].value=c;
				d[k*g].create=1;
				return;
			}
		}

	}
	int CheckLayer(int k,int g)
	{

		int i=layer;
		for(int x=1;x<10;++x)
		{
			if(Number-k*g==x*pow(2.,4-i))
			{
				return 1;
			}
		}

		return 0;
	}
	void DeleteElem()
	{
		int g=1,k=0;

		if((!layer)&&(!d[(Number+1)/2].create))
		{
			printf("tree is empty\n");
			return;
		}


		while(1)
		{
			k=(Number+1)/pow(2.,layer+1);
			if((d[Number-k*g].create)&&(!CheckLayer(k,g)))
			{
				d[Number-k*g].create=0;
				if(Number-k*(g+1)<1)
				{
					--layer;
				}
				return;
			}
			else
			{
				++g;
				if(k*g>=Number)
				{
					d[k*(g-1)].create=0;
				}
			}

		}
	}
	void PrintTree()
	{
		for(int i=0;i<Number;++i)
		{
			if(d[i].create)
			{
				printf("%d ",d[i].value);
			}
		}
		printf("\n");
	}
};




void main()
{
	B a;
	int n;

	while(1)
	{
		printf("0-add elem\n"
			"1-delete elem\n"
			"2-print tree\n");
		scanf("%d",&n);
		switch(n)
		{
		case 0:
			int c;
			printf("New elem\n");
			scanf("%d",&c);
			a.AddElem(c);
			break;
		case 1:
			a.DeleteElem();
			break;
		case 2:
			a.PrintTree();
			break;
		}
	}
}