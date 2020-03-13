function wgtsum = weightsum(pop, weights)
% 计算种群的重量
% pop           input  种群
% weights       input  重量向量
% wgtsum        output 种群重量
popsize = size(pop, 1);
wgtsum = zeros(popsize, 1);
for i = 1:popsize
    wgtsum(i, 1) = weightsumv(pop(i, :), weights);
end
end