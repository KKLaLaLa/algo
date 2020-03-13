function childpop = mutation(pop,pm)


[n,l] = size(pop);
for i = 1:n
    if rand < pm
        r1 = ceil(rand * l);
        r2 = ceil(rand * l);
        temp = pop(i, r1);
        pop(i, r1) = pop(i, r2);
        pop(i, r2) = temp;
    end
end
childpop = pop;
end
