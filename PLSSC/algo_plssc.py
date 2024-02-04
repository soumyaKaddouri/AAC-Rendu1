# Calcul de la taille de la plus longue sous séquence commune avec mémoïsation
# Utilisation d'une approche Top down
D = {}
    
def taille_plssc(X, Y) :

    if(X == () or Y == ()) : return 0

    if (X, Y) in D : return D[(X, Y)]

    if(X[-1] == Y[-1]) : 
        D[(X, Y)] = 1 + taille_plssc(X[:-1], Y[:-1])
    else :
        D[(X, Y)] = max(taille_plssc(X, Y[:-1]), taille_plssc(X[:-1], Y))
        
    return D[(X, Y)] 




# print("\n", taille_plssc((20, 23, 75, 18, 54, 6, 3, 18), (6, 23, 20, 18, 6, 54, 3, 13, 6, 18)), "\n")
# print("\n", D, "\n")



# Calcul de la plus longue sous séquence commune en utilisant une approche Bottom up
def plssc(X, Y) :
    n = len(X)
    p = len(Y)

    # construction de la matrice M
    M = [[0] * (p + 1) for i in range(n + 1)]

    '''
    [0, 0, 0, 0, .... , 0] <--- p+1 0
    [0, 0, 0, 0, .... , 0] <--- p+1 0
    [0, 0, 0, 0, .... , 0] <--- p+1 0
    .
    .
    .
    n + 1 fois
    .
    .
    [0, 0, 0, 0, .... , 0] <--- p+1 0

    '''

    for i in range(n + 1):
        for j in range(p + 1):
            if i == 0 or j == 0:
                M[i][j] = 0
            elif i > 0 and j > 0:
                if X[i - 1] == Y[j - 1]:
                    M[i][j] = 1 + M[i - 1][j - 1]
                elif X[i - 1] != Y[j - 1]:
                    M[i][j] = max(M[i][j - 1], M[i - 1][j])
    
    # Construction de la PLSSC S
    S = ()
    i = n
    j = p

    while (i != 0 and j != 0) :
        if (X[i-1] == Y[j-1]) :
            S = (X[i-1],) + S # ou bien S = (Y[j-1],) + S
            i = i-1
            j = j-1
        else :
            if (M[i][j-1] == M[i-1][j]) :
                i = i-1 # ou bien j = j-1
            elif (M[i][j-1] > M[i-1][j]) :
                j = j-1
            elif (M[i][j-1] < M[i-1][j]) :
                i = i-1
            
    return S


#print("\n", plssc((20, 23, 75, 18, 54, 6, 3, 18), (6, 23, 20, 18, 6, 54, 3, 13, 6, 18)), "\n")
