function [newpop] = selection(pop, fitvalue)
% 选择，轮盘赌方法，最大化问题
% pop       input  种群
% fitvalue  input  适应度值
% newpop    output 选择后的种群
totalfit = sum(fitvalue);
fitvalue = fitvalue / totalfit;
fitvalue = cumsum(fitvalue); %计算每一个元素前的sum
[n, l] = size(pop);
newpop = zeros(n, l);
rnumber = sort(rand(n,1));
fitindex = 1;
newindex = 1;
while newindex <= n
    if rnumber(newindex) < fitvalue(fitindex)
        newpop(newindex,:) = pop(fitindex,:);
        newindex = newindex + 1;
    else
        fitindex = fitindex + 1;
    end
end
end