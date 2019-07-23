#include <stdlib.h>
#include <stdio.h>

// Comment the next line to exclude debug code from compilation
#define DEBUG

#define try runtime_error = 0;
#define catch if (runtime_error > 0)

#define array(type,name,size) type *name = (type *) malloc((size) * \
sizeof(type)); int length_ ## name = (name != NULL ? size : 0);

#define item(array,pos) ((pos) >= 0 && (pos) < length_ ## array  ? array[pos] \
                                                : runtime_error++ )
#define addr(array,pos) ((pos) >= 0 && (pos) < length_ ## array  ? array + pos \
                               : (void *) runtime_error++ )

const int SIZE = 5;
int runtime_error = 0;

int main(void)
{
	extern const int SIZE;
	extern int runtime_error;
	
	int item_val;
	int *item_ptr;
	int i;
	
	array(int, int_array, SIZE);
	
	i = 0;
	
	while (i >= 0)
	{
		try
		{			
			
			item_ptr = addr(int_array,i);
			
			i++;
		}
		catch
		{
			#ifdef DEBUG
			
				printf("\n");
				printf("Array index out of bounds, file %s, line %d, compiled \
          on %s at %s\n", __FILE__, __LINE__, __DATE__, __TIME__);
				printf("\n");
				
			#endif
			
			break;
		}
		
		printf("int_array[%d] : ", i);
		scanf("%d", item_ptr);
		
	}
	
	i = 0;
	
	while (i >= 0)
	{
		try
		{
			item_val = item(int_array,i);
			i++;
		}
		catch
		{
			break;
		}
		
		printf("int_array[%d] : %d\n", i, item_val);
		
	}
	
}
