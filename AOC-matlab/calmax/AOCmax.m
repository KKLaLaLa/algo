%蚁群算法求解函数最大值f = -(x.^4 + 3*y.^4 - 0.2*cos(3*pi*x) - 0.4*cos(4*pi*y) + 0.6);

clear;
clc;

Ant     =   300;    % 蚂蚁数量
Times   =   80;     % 蚂蚁移动次数
Rho     =   0.9;    % 信息素挥发系数
P0      =   0.2;    % 转移概率常数
xl = -1; xu = 1;    % 设置搜索范围
yl = -1; yu = 1;
step = 0.05;

ants = initant(Ant, xl, xu, yl, yu);    % 初始化蚁群
tau = calObjFun(ants);                  % 计算初代信息素
firstants = ants;

for t = 1:Times
    ants = edgeselection(ants, tau, P0, 1/t, xl, xu, yl, yu);    % 转移+约束
    tau = (1 - Rho) .* tau + calObjFun(ants);               % 更新信息素
end

figure(1);
plotobjfun(xl, xu, yl, yu, step);
hold on;
plot3(firstants(:,1), firstants(:,2), calObjFun(firstants), 'b*');
hold on;
plot3(ants(:,1), ants(:,2), calObjFun(ants), 'r*');
hold off;