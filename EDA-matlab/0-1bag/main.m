function main()
capacity = load("p08_c.txt");       % 背包容量
bks = load("p08_s.txt");            % 最优解
bks = bks';
weights = load("p08_w.txt");        % 重量
weights = weights';
profits = load("p08_p.txt");        % 收益
profits = profits';

popsize = 100;                  % 群体规模
maxgen = 50;                    % 迭代次数
stuffsize = length(weights);    % 物品数量
p = ones(1, stuffsize) .* 0.5;  % 概率向量
alpha = 1;                      % 学习速率
sn = 0.7;                       % 优势个体数量
sn = ceil(popsize * sn);

bestselection = zeros(maxgen, stuffsize);   % 记录每代最优选择
avgweights = zeros(1, maxgen);              % 记录每代平均收益

for gen = 1:maxgen
    pop = makepop(popsize, stuffsize, p);               % 制作种群
    pop = capacitylimit(pop, capacity, weights, p);     % 限制重量

    wgtsum = weightsum(pop, weights);
    [~, index] = max(wgtsum);
    bestselection(gen, :) = pop(index, :);
    avgweights(1, gen) = sum(wgtsum) / popsize;

    spop = selection(pop, sn, profits);     % 选择优势个体
    p = makep(spop, p, alpha);              % 更新概率向量
end
wgtsum = weightsum(bestselection, weights);
[~, index] = max(wgtsum);
figure(1);
plot(1:1:maxgen, wgtsum');
title("每代最优选择收益图");
figure(2);
plot(1:1:maxgen, avgweights);
title("每代平均收益图");
end