#include<stdio.h>
#include<stdlib.h>

/* Definition of the Pixel Data Type */
typedef struct pixel 
{
int red;
int blue;
int green;
} pixel;

int main()
{
	int i,j;
	int m,n,max;				    /* The dimensions of the image. */
	pixel *Image; 			/* A pointer that will be used to allocate an Array representing the image. */
	char ppm_type[3]; 
	FILE *input_ppm_image,*output_ppm_image;
	

	/* File Handling */
	
	input_ppm_image = fopen("Basic.ppm","r");
	if(input_ppm_image == NULL)
			printf("404 motivation to do this not found.\n"); 
	else
	{
		fscanf(input_ppm_image,"%s",ppm_type); /* Read the type of the PPM image */

		if(strcmp(ppm_type,"P3"))
			printf("PPM image type not supported!\n");
		else
		{
	
 	 		fscanf(input_ppm_image,"%d %d %d",&m,&n,&max); /* Read the dimensions and the max. colour value of the PPM image */
			pixel array[m][n];
			/* Allocate the image */
			Image = malloc(sizeof(pixel)*m);
	
			/* Read the first row of the image */
			output_ppm_image = fopen("Basic_row.ppm","w");
			fprintf(output_ppm_image,"%s\n",ppm_type); 
			printf("%s\n", ppm_type);
			fprintf(output_ppm_image,"%d %d\n%d\n",m,n,max); 
			printf("%d %d %d\n",m,n,max);
			for(j=0;j<n;j++)
			{
				for(i=0;i<m;i++)
				{
				  	fscanf(input_ppm_image,"%d %d %d",&Image[i].red,&Image[i].green,&Image[i].blue); /* Read the PPM image */ 				  	
				  	//printf("%d\n%d\n%d\n",Image[i].red,Image[i].green,Image[i].blue); 
				  	fprintf(output_ppm_image,"%d\n%d\n%d\n",Image[i].red,Image[i].green,Image[i].blue);
				  	array [i][j] = Image[i]; 
				  	printf("%d %d %d\n",array[i][j].red, array[i][j].green, array[i][j].blue);
				}
				
			}
			printf("\n");
			/*for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if ((array[i][j].red==0 && array[i][j].green==0) && array[i][j].blue==0)
					{
						array[i][j].red=255;	
						printf("%d %d %d\n",array[i][j].red, array[i][j].green, array[i][j].blue);
						
					}
				}
			}					
			*/
			fclose(output_ppm_image);
		}
	}
	free(Image);
	fclose(input_ppm_image);
	return 0;
}
