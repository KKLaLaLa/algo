clc;
clear;

NP  = 20;       % 种群规模
D   = 2;        % 参数个数
G   = 30;       % 最大进化代数
F   = 0.5;      % 缩放因子
Cr  = 0.8;      % 交叉因子

xl  = -4;       % x下限（也是y下限）
xu  = 4;        % x上限（也是y上限）

bestvalue = zeros(3, G);

% 优化
gen = 0;
pop = initpop(NP, D, xl, xu);
objvalue = calobj(pop);
while gen < G
    mpop = mutation(pop, F);                    % 变异
    cpop = crossover(pop, mpop, Cr);            % 交叉
    cpop = constrictboundary(cpop, xl, xu);     % 约束边界
    pop = selection(pop, cpop);                 % 选择
    objvalue = calobj(pop);
    gen = gen + 1;

    % 记录最优
    [~, index] = min(objvalue);
    bestvalue(1:2, gen) = pop(index,:)';
    bestvalue(3,gen) = objvalue(index);
end

fprintf('bestX = %f, bestY = %f, bestZ = %f\n', ...
    bestvalue(1,end), bestvalue(2,end), bestvalue(3,end));

% 绘图
figure(1);
x = [-4:0.1:4]; y = [-4:0.1:4];
[X, Y] = meshgrid(x, y);
Z = 3 * cos(X .* Y) + X + Y;
surf(X, Y, Z);
hold on;
scatter3(bestvalue(1,:), bestvalue(2,:), bestvalue(3,:), ...
    'MarkerEdgeColor','k', 'MarkerFaceColor',[0 .75 .75]);
xlabel('x'); ylabel('y'); zlabel('z'); title('函数图');
hold off;

figure(2);
plot(bestvalue(3,:));
xlabel('进化代数'); ylabel('最优目标函数值'); title('目标函数值变化图');
