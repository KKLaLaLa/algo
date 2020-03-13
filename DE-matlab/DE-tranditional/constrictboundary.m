function newpop = constrictboundary(pop, xl, xu)
% 约束边界（边界吸收）
% pop       input  种群
% xl        input  自变量最小值（包含）
% xu        input  自变量最大值（包含）
% newpop    output 约束边界后的种群
newpop = pop;
newpop(newpop < xl) = xl;
newpop(newpop > xu) = xu;
end