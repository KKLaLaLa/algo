function fitness = calfitness(x)
% 计算适应度值
% f = sum(x^2+x-6)
% x         input  种群
% fitness   output 适应度值
x = x .^ 2 + x - 6;
fitness = sum(x, 2);
end