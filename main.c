#include <stdio.h>
#include <stdlib.h>
#include <string.h> //֧���ַ�������
#include <time.h>
#define MAX 6      //����MAX��ʾϵͳҪ��������������
/*
 * ��Ҫ�ر��г�����չ֪ʶ�㣺
 * 1�����������ĺ���������������
 * 2��Sleep()����
 * 3���ַ������鼰�򵥵��ַ�����������Ƚϡ�����
 * 4��ʱ�亯����exit����
 */

#define DAY_COUNT 10

int main()
{
    printf("\n\n\n********************�ڶ����޸��˵�һ�汾�Ĳ���BUG�������������ģ�������Ʒ�����ڴ���********************\n\n\n");
    int i,j,temp,k;                                                     //ѭ�������Լ���ʱ���α���
    int count = 5;                                                      //��ǰδ�����乬����������
    char tempName[20];                                                  //���������ʱ��������
    int index = -1;                                                     //������ʾ�Ƿ��ҵ���ѡ����
    int searchIndex = -1;                                               //������Ų���Ԫ�ص��±�
    int choice;                                                         //�ʵ۵�ѡ��1-4֮��
    int num = 0;                                                        //�����ж����Ӻøж���60���µĸ���
    //ʹ���ַ������ʾ�ַ���
    char emperorName[50];                                               //�ʵ۵�����
    char names[MAX][50] = {"����","����","��ʩ","����","��Ŀ"};       //����������
    char levelNames[5][10] = {"����","����","����","�ʹ���","�ʺ�"};    //�����ļ���

    //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int levels[MAX] = {0,0,0,0,0,-1};

    //loves�е�ÿ��Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ���ÿ���˵ĺøжȶ���100
    int loves[MAX] = {100,100,100,100,100,-1};

        printf("\n*******************************************************************\n");
        printf("�鿴��ǰ������״̬��\n");
        printf("%-12s\t����\t\t�øж�\n\n","����");
        for(i = 0;i < count; i++)
        {
            printf("%-12s\t%s\t\t%d\t\t\n\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("\n*******************************************************************\n");


        //����Ŀ¼
        printf("�����뵱ǰ�ǻ��Ļʵ����ţ�\n");
        scanf("%s",emperorName);//¼���ַ���ʱ������Ҫ&����
        printf("�ʵ�%s�ǻ�������",emperorName);
        printf("�������������꣡����\n");
        for(k = 0;k < DAY_COUNT;k++)
        {
            printf("1���ʵ���ּѡ����\t\t(���ӹ���)\n");
            printf("2�����Ƴ��ң�\t\t\t(�޸�״̬����)\n");
            printf("3�������乬��\t\t\t(ɾ������)\n");
            printf("4�������ټ�����!\n");
            printf("������ѡ��\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    //�ʵ���ּѡ����\t\t(���ӹ���)
                    //1.����ǰ���ж�������û�пռ�
                    //2.��������Ԫ��(names,loves,levels)
                    if(count < MAX)//�����ǰ��������С��ϵͳ�����
                    {
                        //ִ����Ӳ���
                        printf("���������ӵ����䣺\n");
                        scanf("%s",names[count]);
                        //����count��Ԫ�ص�״̬��ʼ��
                        levels[count] = 0;  //�����ʼΪ0
                        loves[count] = 100; //�øжȳ�ʼΪ100
                        count++; //�����������ǵ����Ӽ�����
                    }
                    else
                    {
                        printf("������Ϊ����\n���ʧ�ܣ�\n");
                        break;
                    }
                    for(i = 0;i < count - 1;i++)
                    {
                        loves[i] -= 10;
                    }
                    break;

                case 2: //���Ƴ��ң�\t\t(�޸�״̬����)\n
                        //1.�ҵ�Ҫ�������ӵ��±�
                        //2.�޸����Ӻõ�״̬
                        //�øж�+10�����������������߼�������
                        //3.�޸���������״̬   �øж�-10��

                    printf("���£���������췭�����ӵ����䣺\n");
                    scanf("%s",tempName);
                    //�ַ����Ĳ���strcmp,��Ҫ����<string.h>ͷ�ļ�
                    //trcmp(tempName,"abc") == 0  ---�����ַ������
                    //trcmp(tempName,"abc") == 1  ---ǰһ���ַ�����
                    //trcmp(tempName,"abc") == -1 ---��һ���ַ�����
                    for(i = 0;i < count;i++)
                    {
                        if(strcmp(tempName,names[i]) == 0)
                        {
                            loves[i] += 10;
                            //�����ܳ���5����0-4֮�䣩
                            levels[i] = levels[i] >= 4 ? 4:levels[i] + 1;
                            index = i;
                            break;
                        }
                    }
                    if(index == -1)
                        printf("\n**********���޴��ˣ�**********\n\n");
                    else
                        for(i = 0;index != -1&&i < count;i++)
                        {
                            if(i != index)
                            {
                                loves[i] -= 10;
                                levels[i] = levels[i] <= 0 ? 0:levels[i] - 1;
                            }
                            else continue;
                        }
                    index = -1;
                    break;
                case 3:
                    //1.����
                    //2.����һ����ֵ��ǰ��һ��Ԫ��
                    //3.����--
                    //4.�޸���������״̬���øж�ͳһ����

                    printf("���£�������Ҫ�����乬�����ӵ�����\n");
                    scanf("%s",tempName);
                    //ѭ������
                    for(i = 0;i < count;i++)
                    {
                        if(strcmp(tempName,names[i]) == 0)//�Ƚ��ַ����Ƿ����
                        {
                            //��¼��Ҫ���ҵ��±꣬Ȼ�����
                            searchIndex = i;
                            break;
                        }
                    }
                    if(searchIndex == -1)//��ʾû���ҵ�
                    {
                        printf("������˼��������Ц\n");
                    }
                    else
                    {
                        for(i = searchIndex;i < count - 1;i++)
                        {
                            //names[i] = names[i + 1];
                            //��Ϊ���ַ���
                            //c�в�֧�������ֱ�Ӹ�ֵ
                            //��Ҫʹ��strcpy����ʵ�����鸳ֵ
                            //�����γ���ϸ����
                            strcpy(names[i],names[i + 1]);
                            loves[i] = loves[i + 1];
                            levels[i] = levels[i + 1];
                        }
                        count--;
                    }
                    break;

                case 4:
                    //1.����
                    //2.���Ӻøжȼ���
                    //3.��������ʹ���������ʫ��
                    //ʹ��������ֵķ�ʽ�����ֻʵ��Ĳ�

                    printf("���£���ѡ��Ҫ�ټ������ӣ�\n");
                    scanf("%s",tempName);
                    for(i = 0;i < count;i++)
                    {
                        if(strcmp(tempName,names[i]) == 0)
                        {
                            loves[i] += 10;
                            //�����ܳ���5����0-4֮�䣩
                            levels[i] = levels[i] >= 4 ? 4:levels[i] + 1;
                            index = i;
                            break;
                        }
                    }
                    if(index == -1)  printf("���޴��ˣ�\n");
                    index = -1;
                    break;
                default:printf("����Ϸ�ԣ��������˼��\n");break;
            }

            //����ӡ��������״̬ǰ
            //�Լ����������ʹ��ð������
            for(i = 0;i < count - 1;i++)
            {
                for(j = 0;j < count - i - 1;j++)
                {
                    if(levels[j] < levels[j + 1])
                    {
                        //��Ҫ��������������ͺøж�
                        temp = levels[j];
                        levels[j] = levels[j + 1];
                        levels[j + 1] = temp;
                        temp = loves[j];
                        loves[j] = loves[j + 1];
                        loves[j + 1] = temp;
                        //ע���ַ�����
                        strcpy(tempName,names[j]);
                        strcpy(names[j],names[j + 1]);
                        strcpy(names[j + 1],tempName);
                    }
                }
            }

            printf("\n*******************************************************************\n");
            printf("�鿴��ǰ������״̬��\n");
            printf("%-12s\t����\t\t�øж�\n\n","����");
            for(i = 0;i < count; i++)
            {
                printf("%-12s\t%s\t\t%d\t\t\n\n",names[i],levelNames[levels[i]],loves[i]);
            }
            printf("\n*******************************************************************\n");

        for(i = 0;i < count;i++)
        {
                if(loves[i] < 60)
                {
                    printf("����\"%s\"�ĺøж��Ѿ�������60һ�£����������!\n",names[i]);
                    num++;
                }
        }
        if(num == 0)
            printf("���Ǳ���ִ����%d�죬��һƬ���~\n",k + 1);
        else printf("���Ǳ���ִ����%d��\n\t����%dλ����Ա���Թ������\n\t\t������³�ȥ̽��\n",k + 1,num);
        num = 0;
        }
    return 0;
}
