function fitness = calfitness(x)
% ������Ӧ��ֵ
% f = sum(x^2+x-6)
% x         input  ��Ⱥ
% fitness   output ��Ӧ��ֵ
x = x .^ 2 + x - 6;
fitness = sum(x, 2);
end