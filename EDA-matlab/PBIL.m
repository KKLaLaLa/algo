%%%%%%%%%%%%PBIL algorithm
clc
clear
clf
tic           %%%%%%%%%%%开始计时
%%%%%%%%%%%%参数设置
Pop_Size=40;
Individual_Len=20;%%%%%%%%%每个变量的长度；二进制
Variable_Num=2;
Learning_Rate=0.01;
Iteration_Times=1000; %%%%%迭代次数
I=1;
%%%%%%%%%%%%%%%产生初始种群，使用随机数生成
Binary_X=zeros(Pop_Size,Variable_Num,Individual_Len);
for i=1:1:Pop_Size
    for j=1:1:Variable_Num
        for k=1:1:Individual_Len
            Binary_X(i,j,k)=round(rand());
        end
    end
end
Best_Individual=zeros(1,Iteration_Times);
Probability_Vector=zeros(Iteration_Times,Variable_Num,Individual_Len);
traces=zeros(3,Iteration_Times);%%%%%追踪每一代的最优值
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%对每一代执行如下操作
while I<=Iteration_Times    
 %%%%%%%%%%%%%%%%将采样的值，由二进制转化到十进制
  Decimal_X=zeros(Pop_Size,Variable_Num);
    for i=1:1:Pop_Size
        for j=1:1:Variable_Num  
            k=Individual_Len;
            t=1;
            while k>=1
               Decimal_X(i,j)=Decimal_X(i,j)+Binary_X(i,j,k)*2^(t-1);
               k=k-1;
               t=t+1;
            end
        end
    end
    %%%%%%%%%%%%%%%%%将十进制映射到解空间中
    Solution=zeros(Pop_Size,Variable_Num);
    for i=1:1:Pop_Size
        for j=1:1:Variable_Num
            Solution(i,j)=-2+Decimal_X(i,j)*4/(2^Individual_Len-1);
        end
    end
    %%%%%%%%%%%%%%%%%%计算适应值
    Fitness_Value=zeros(1,Pop_Size);
    for i=1:1:Pop_Size
      %  Fitness_Value(i)=100*(Solution(i,1)^2-Solution(i,2))^2+(1-Solution(i,1))^2;
    %  Fitness_Value(i)=Solution(i,1)*cos(2*pi*Solution(i,2))+Solution(i,2)*sin(2*pi*Solution(i,1));
    %Fitness_Value(i)=Solution(i,1)+Solution(i,2);
   % Fitness_Value(i)=Solution(i,1)^2+Solution(i,2);
   %Fitness_Value(i)=Solution(i,1)*Solution(i,2);
   %Fitness_Value(i)=(Solution(i,1)-Solution(i,2))^2;
    Fitness_Value(i)=Solution(i,1).*cos(2*pi*Solution(i,2))+Solution(i,2).*cos(2*pi*Solution(i,1));
    end
    %%%%%%%%%%%%%%%%%%将适应值按照从小到大的顺序排序，并选出最优个体
    [FitnessValue,index]=sort(Fitness_Value);%%%%%%%排序  
    Best_Individual(I)=Fitness_Value(index(Pop_Size));%%%%%%%%选最优个体
    traces(1,I)=Solution(index(Pop_Size),1);
    traces(2,I)=Solution(index(Pop_Size),2);
    traces(3,I)=Fitness_Value(index(Pop_Size));
    %%%%%%%%%%%%%%%%选出优势群体
    Superiority_Polution=zeros(Pop_Size/2,Variable_Num,Individual_Len);
    for i=1:1:Pop_Size/2
        for j=1:1:Variable_Num
            for k=1:1:Individual_Len
                Superiority_Polution(i,j,k)=Binary_X(index(i+Pop_Size/2),j,k);
            end
        end
    end
    %%%%%%%%%%%%%%%从优势群体中统计基因位的值，来更新概率向量
     Ones_Number=zeros(Variable_Num,Individual_Len);
    for i=1:1:Pop_Size/2
        for j=1:1:Variable_Num
            for k=1:1:Individual_Len
                if Superiority_Polution(i,j,k)==1
                    Ones_Number(j,k)=Ones_Number(j,k)+1;
                end
            end
        end
    end
    for j=1:1:Variable_Num
        for k=1:1:Individual_Len
            Probability_Vector(I,j,k)=Ones_Number(j,k)/(Pop_Size/2);
        end
    end
%%%%%%%%%%%%%%更新概率向量pbil算法       
if I>1
       for j=1:1:Variable_Num
           for k=1:1:Individual_Len
               Probability_Vector(I,j,k)=Learning_Rate.*Binary_X(index(Pop_Size),j,k)+(1-Learning_Rate).*Probability_Vector(I-1,j,k);
           end
       end
end
    %%%%%%%%%%%%%%%%根据概率向量对解空间采样
    for i=1:1:Pop_Size
        for j=1:1:Variable_Num
            for k=1:1:Individual_Len
                r=rand();
                if r<Probability_Vector(I,j,k)
                    Binary_X(i,j,k)=1;
                else
                    Binary_X(i,j,k)=0;
                end
            end
        end
    end
   %%%%%%%%%%%%%%%%%%%%  执行如上操作就得到了下一代群体
   I=I+1;
end                   %%%%%%%%%%%%%%迭代终止
toc             %%%%%%%%%%%%%计时终止，显示程序运行所用的时间
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%画图

figure(1)
hold on
xlabel('进化代数')
ylabel('最优解的变化')
plot(Best_Individual);
title('进化过程')
grid on
[Best_Polution,xuhao_Iteration]=max(Best_Individual);
bestx1=traces(1,xuhao_Iteration);
bestx2=traces(2,xuhao_Iteration);
bestz=traces(3,xuhao_Iteration);
fprintf(['最优解:\nx1=',num2str(bestx1),'\nx2=',num2str(bestx2),'\nf=',num2str(bestz),'\niteration=',num2str(xuhao_Iteration),'\n']);
hold off



