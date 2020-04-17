%%%一个旅行商人要拜访全国31个省会城市，需要选择最短的路径%%%%
%种群数目NP=200
%免疫个体维数N=31
%迭代次数G=1000
%克隆个体个数为Ncl=10
%任意两个城市的距离矩阵D

%%%免疫算法解决TSP问题%%%%%%%
%%%初始化%%%%%%%
clear all; %清除所有变量
close all; %清图
clc ;      %清屏
%%全国31个省会城市的坐标
C=[
1304 2312;
3639 1315;
4177 2244;
3712 1399;
3488 1535;
3326 1556;
3238 1229;
4196 1004;
4312 790;
4386 570;
3007 1970;
2562 1756;
2788 1491;
2381 1676;
1332 695;
3715 1678;
3918 2179;
4061 2370;
3780 2212;
3676 2578;
4029 2838;
4263 2931;
3429 1908;
3507 2367;
3394 2643;
3439 3201;
2935 3240;
3140 3550;
2545 2357;
2778 2826;
2370 2975
];%31个省会坐标

N=size(C,1); %TSP问题的规模，即城市数目
D=zeros(N);  %任意两个城市距离间隔矩阵,初始化都为0

 %任意两个城市距离间隔矩阵%
 for i=1:N
     for j=1:N
         D(i,j)=((C(i,1)-C(j,1))^2+(C(i,2)-C(j,2))^2)^0.5;
     end
 end  
 
 NP=200;  %免疫个体数目
 G=1000; %最大免疫代数
 f=zeros(N,NP); %用于存储种群
 
  for i=1:NP
     f(:,i)=randperm(N); %随机生成初始种群
  end
  
  len=zeros(NP,1);  %存储路径长度
  for i=1:NP
    len(i)=func3(D,f(:,i),N); %随机生成初始种群
  end
  
  [Sortlen,Index]=sort(len);
  Sortf=f(:,Index);    %种群个体排序
  gen=0;               %免疫代数
  Nc1=10;             %克隆个数
  
  %%%%%%%%%%%%%%%%%%%%%%免疫循环%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  while gen<G
      %%%%%%%%%%%%%%%%%选激励度前NP/2个个体进行免疫操作%%%%%%%%%%%
      for i=1:NP/2
          
          a=Sortf(:,i);
          Ca=repmat(a,1,Nc1);
          for j=1:Nc1
              p1=floor(1+N*rand());
              p2=floor(1+N*rand());
              while p1==p2
              p1=floor(1+N*rand());
              p2=floor(1+N*rand());
              end
              %%元素的交换
              temp=Ca(p1,j);
              Ca(p1,j)=Ca(p2,j);
              Ca(p2,j)=temp;
          end
          Ca(:,1)=Sortf(:,i);   %保留克隆源个体
          %%%%%%%%%%%%%%%%克隆抑制，保留亲和度最高的个体%%%%%%%%%%%%%%%%
          for j=1:Nc1
              Calen(j)=func3(D,Ca(:,j),N);
          end
          [SortCalen,Index]=sort(Calen);
          SortCa=Ca(:,Index);
          af(:,i)=SortCa(:,1);
          alen(i)=SortCalen(1);
      end
      %%%%%%%%%%%%%%%%%种群刷新%%%%%%%%%%%
      for i=1:NP/2
          bf(:,i)=randperm(N); %随机生成初始种群
          blen(i)=func3(D,bf(:,i),N); %计算路径长度
      end
      %%%%%%%%%%%%%%%%%免疫种群与新种群合并%%%%%%%%%%%
      f=[af,bf];
      len=[alen,blen];
      [Sortlen,Index]=sort(len);
      Sortf=f(:,Index);
      gen=gen+1;
      trace(gen)=Sortlen(1);
  end
  
  %%%%%%%%%%%%%%%%%%%%%%输出优化结果%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Bestf=Sortf(:,1);   %最优变量
  Bestlen=trace(end);  %最优值
  %%%%%图1
  figure 
  for i=1:N-1
     plot([C(Bestf(i),1),C(Bestf(i+1),1)],...
           [C(Bestf(i),2),C(Bestf(i+1),2)],'bo-');
     hold on;
  end
  
   plot([C(Bestf(N),1),C(Bestf(1),1)],...
         [C(Bestf(N),2),C(Bestf(1),2)],'ro-');
   title(['优化最短距离:',num2str(trace(end))]);
   %%%%图2
   figure 
   plot(trace)
   xlabel('迭代次数')
   ylabel('目标函数值')
   title('亲和度进化曲线')

   
   
   