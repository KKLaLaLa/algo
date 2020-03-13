function p = makep(spop)
% 更新概率矩阵
% spop          input  优势群体
% np            output 概率矩阵
[popsize, citysize] = size(spop);
count = zeros(citysize, citysize);   % 记录出现次数
spop = [spop spop(:, 1)];
for i = 1:popsize
    for j = 1:citysize
        a = spop(i, j);
        b = spop(i, j+1);
        count(a, b) = count(a, b) + 1;
        count(b, a) = count(b, a) + 1;
    end
end
sumcount = sum(count, 2);
p = count ./ sumcount;
end