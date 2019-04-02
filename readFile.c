#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * fp1;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    float* dataX = (float*)malloc(4*sizeof(float));
    
    // Open file
    fp1 = fopen("./lat.txt", "r");
    if (fp1 == NULL){
        exit(EXIT_FAILURE);
    }
        
    /* Read while there is line with content */
    while ((read = getline(&line, &len, fp1)) != -1) {
        printf("%s", line);
    }

    /* Read sepeciffic number of lines */
    for (int k=0; k<4; k++) {
        getline(&line, &len, fp1);
        dataX[k] = atof(line);
        printf("FloatX: %.4f\n",dataX[k]);
    }

    fclose(fp1);
    if (line){
        free(line);
    }
    free(dataX);

    exit(EXIT_SUCCESS);
}
