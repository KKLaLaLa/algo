function len = callength(pop, dm)
% «Û¬∑æ∂æ‡¿Î
% pop           input  ÷÷»∫
% dm            input  æ‡¿Îæÿ’Û
% len           output æ‡¿Î
[NP, D] = size(pop);
pop = [pop pop(:,1)];
sum = zeros(NP, 1);
for i = 1:NP
    for j = 1:D
        sum(i,1) = sum(i,1) + dm(pop(i, j), pop(i, j+1));
    end
end
len = sum;
end