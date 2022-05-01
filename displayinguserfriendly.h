char temp_path[255];
void forcontinutionofprompt(char cwd[],char current_path[])
{
    int i,j,k,count = 0;
    for(int y = 0; y<255;y++)
    {
        temp_path[y] = 0;
    }
    temp_path[0]='~';
	temp_path[1]='/';
	for(i = 0;i<strlen(cwd)&&cwd[i]==current_path[i];i++)
    {
        count++;
    }
	
	for(i = count+1,k = 2;i<strlen(current_path);i++,k++)
		temp_path[k]=current_path[i];


	if(count==strlen(cwd))
		prompt(temp_path);
	else
		prompt(current_path);
}
void removimghomedir_path(char given_path[],char executablepath[])
{
    int i,j,k,count = 0;
    for(int y = 0; y<255;y++)
    {
        temp_path[y] = 0;
    }
    temp_path[0]='~';
	temp_path[1]='/';
	for(i = 0;i<strlen(given_path)&&given_path[i]==executablepath[i];i++)
    {
        count++;
    }
	
	for(i = count+1,k = 2;i<strlen(executablepath);i++,k++)
		temp_path[k]=executablepath[i];


	if(count==strlen(given_path))
		printf("Executable Path :%s\n",temp_path);
	else
		printf("Executable Path :%s\n",given_path);
}

