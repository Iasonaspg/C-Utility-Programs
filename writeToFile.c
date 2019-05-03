void writeToFile(char* filename, double* times, int len){
  FILE* fp1;
  fp1 = fopen(filename,"w");

  for (int i=0;i<len;i++){
    fprintf(fp1,"%lf\n",times[i]);
  }
}
