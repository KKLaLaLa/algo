function pop = initpop(popsize, chromlength, xl, xu)
% 生成初始种群
% popsize           input  种群规模
% chromlengt        input  染色体长度
% xl                input  x下限
% xu                input  x上限
% pop               output 种群
pop = rand(popsize, chromlength) * (xu - xl) + xl;
end