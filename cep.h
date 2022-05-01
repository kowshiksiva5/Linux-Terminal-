char current_path[255];
char temp_path[255];

int command1(char command_input[][500],char given_path[],int count)
{
	//printf("input = %s\n",command_input[0]);
	//printf("entered\n");
	int i,j,k;
	i=0;
	while(i<20)
	{
		if(strcmp(command_input[i],"&")!=0)
		{
			i++;
			continue;
		}
		else
		{
			return 0;
		}

	}
	if(strcmp(command_input[0],"pwd") == 0)
	{
		//printf("  the pwd\n");
		for(int t1 = 0;t1 < 255;t1++)
		{
			current_path[t1] = 0;
		}
		getcwd(current_path,255);
		printf("%s\n",current_path);
		return 1;
	}
	else if(strcmp(command_input[0],"cd") == 0)
	{
		//printf(" the cd\n");
		char s[255];
		//strcpy(command_input[count],"");
		//printf("%s\n",getcwd(s,255));
		if(strcmp(command_input[1],".")==0)
		{
			return 1;
		}
		else if(strcmp(command_input[1],"..")==0)
		{
			chdir("..");
			//printf("%s\n",getcwd(s,255));

		}
		else if(strcmp(command_input[1],"~")==0)
		{
			chdir(given_path);
			//printf("%s\n",getcwd(s,255));

		}
		else if(strcmp(command_input[1],"~/")==0)
		{
			chdir(given_path);
			//printf("%s\n",getcwd(s,255));

		}
		else 
		{
			//printf(" last in cd\n");
			for(int t1 = 0;t1 < 255;t1++)
			{
				current_path[t1] = 0;
			}
			getcwd(current_path,255);
			if(command_input[1][0] == '~' && command_input[1][1] == '/')
			{
				for(int t1 = 0;t1 < 255;t1++)
				{
					current_path[t1] = 0;
				}
				getcwd(current_path,255);
				for(int t1 = 0;t1 < 255;t1++)
				{
					temp_path[t1] = 0;
				}
				for(j=0,k=2;j<strlen(command_input[1]);j++,k++)
				{
					temp_path[j] = command_input[1][k];
				}
				if(chdir(temp_path)!=0 )
				{
					printf("Sorry,No such file or Diretory exists\n");
				}
			}
			else
			{
				//printf("command_input[1] = %scommand_input[0] = %s\n",command_input[1],command_input[0]);
				int ty = chdir(command_input[1]);
				if(ty !=0)
				{
					printf("Sorry,No such file or Diretory exists\n");
				}
				//printf("%s\n",getcwd(s,255));
			}
		}
		return 1;
	}
	
	else if (strcmp(command_input[0],"ls")==0)
	{
		int flag =0,temp = 0;
		//printf("%s %s %s %s \n",command_input[0],command_input[1],command_input[2],command_input[3]);
		if(strcmp(command_input[1],"-l")==0)
		{
			if(strcmp(command_input[2],"-a")==0)
			{
				flag = 3;
				fun_la(command_input,given_path,flag,temp);
			}
			else
			{
                flag = 2;
                temp = 1;
				fun_la(command_input,given_path,flag,temp);
			}

		}
		else if(strcmp(command_input[1],"-a")==0)
		{
			
			if(strcmp(command_input[2],"-l")==0)
			{
				flag = 3;
				fun_la(command_input,given_path,flag,temp);
			}
			else if(command_input[2][0]==0)
			{
				print_hidden(".");
			}
			else
			{
				print_hidden(command_input[2]);
			}
		}
		else if(strcmp(command_input[1],"-la")==0 || strcmp(command_input[1],"-al")==0)
		{
			flag = 2;
			fun_la(command_input,given_path,flag,temp);
		}
		else
		{
			if(strcmp(command_input[1],"")==0)
			{
				print_nonhidden(".");
			}
			else
			{
				print_nonhidden(command_input[1]);
			}
		}
	}
    else if(strcmp(command_input[0],"pinfo")==0)
	{
		return  command_pinfo(command_input,given_path);
	}
    else if(strcmp(command_input[0],"history")==0)
	{
		int t1,t2,t;
        if(strcmp(command_input[1],"")!=0)
		{
			if(command_input[1][1]!=0)
			{
				t1 = command_input[1][0] - '0' ;
				t2 = command_input[1][1] - '0' ;
				t = t1*10 + t2;
				printf("t = %d t1 = %d t2 = %d\n",t,t1,t2);
			}
			else
			{
				t = command_input[1][0] - '0';
			}
			
		}
		history(t);
	}

	else
	{
		printf("command is not Included\n");
	}
}
