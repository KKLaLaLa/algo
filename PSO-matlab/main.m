
popsize = 50;       % 种群规模
birdsize = 30;      % 粒子数量
w = 0.5;            % 惯性权重
c1 = 1.0;           % 认知因子
c2 = 2.0;           % 社会因子
maxgen = 100;       % 最大迭代次数

% 初始化
x = randn(popsize, birdsize);
v = randn(popsize, birdsize);

% 初始化pid，pgd
fitness = calfitness(x);
pid = x;
pidfit = fitness;
[bfit, bfiti] = min(fitness);
pgd = x(bfiti, :);
pgdfit = bfit;

% 记录每代最优值
bestpidfit = zeros(popsize, 1);

for gen = 1:maxgen
    % 更新速度和位置
    v = w .* v + c1 .* rand .* (pid - x) + ... 
        c2 .* rand .* (repmat(pgd, popsize, 1) - x);
    x = x + v;

    % 更新pid，pgd
    fitness = calfitness(x);
    index = find(fitness < pidfit);
    pid(index, :) = x(index, :);
    pidfit(index, 1) = fitness(index, 1);
    [bfit, bfiti] = min(fitness);
    bestpidfit(gen, 1) = bfit;
    if bfit < pgdfit
        pgd = x(bfiti, :);
        pgdfit = bfit;
    end
end
fprintf("函数最小值： %f\n", pgdfit);
figure(1);
plot(1:maxgen, bestpidfit);
title("每代最优适应度值变化曲线");




