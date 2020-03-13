function bestindex = bestindividual(pop, fitvalue, opt)
% 得到种群中最优的个体的索引
% pop               input  种群
% fitvalue          input  适应度值
% opt               input  操作模式:'min'求最小值,'max'求最大值
% bestindex         output 最优个体索引
if strcmp(opt, 'min')
    [~, bestindex] = min(fitvalue);
else
    [~, bestindex] = max(fitvalue);
end
end