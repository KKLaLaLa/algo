function main()
pos = [randperm(20); randperm(20)];
% pos = load('berlin52.txt'); % 7542
% pos = pos(:, 2:3);
% pos = pos';

popsize = 300;                  % 种群规模
maxgen = 100;                   % 最大迭代次数
citysize = size(pos, 2);        % 城市数量
p = ones(citysize, citysize);   % 概率矩阵
sn = ceil(popsize * 0.5);       % 优势群体规模
dm = makedm(pos);               % 距离矩阵

bestlists = zeros(maxgen, citysize);    % 记录每代最优解
bestfits = zeros(1, maxgen);            % 记录每代最优解适应度值
avgfits = zeros(1, maxgen);             % 记录每代平均适应度值

for gen = 1:maxgen
    pop = makepop(popsize, citysize, p);    % 制作种群

    fitness = callength(pop, dm);
    [bfit, bfiti] = min(fitness);
    bestlists(gen, :) = pop(bfiti, :);
    bestfits(1, gen) = bfit;
    avgfits(1, gen) = sum(fitness) / popsize;

    spop = selection(pop, sn, fitness);     % 选择优势群体
    p = makep(spop);                        % 更新概率矩阵
end
fitness = callength(bestlists, dm);
[bfit, bfiti] = min(fitness);
fprintf("最短距离: %f\n", bfit);
end