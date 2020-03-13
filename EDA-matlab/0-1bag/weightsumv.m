function wgtsum = weightsumv(stuffs, weights)
% 计算一个个体的重量
% stuffs        input  物品序列
% weights       input  重量向量
% wgtsum        output 个体重量
wgtsum = sum(weights(stuffs ~= 0));
end