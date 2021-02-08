# C-project
Pour la compilation vous devez avoir: mingw32 et SDL2-2.0.10(il y a déjà dans le dossier othello) SDL_ttf et SDL_image.
Pour la commande pour la  compilationa(le racine est dossier othello) : gcc -std=c17 othello.c fonction_Tritement_fichier.c logique_jeu.c SDLfonction.c -IC:\Users\Zouheir\Desktop\projectc\othello -LC:\Users\Zouheir\Desktop\projectc\othello\lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o Othello
Note bien : le chemin doit être modifie selon utilisateur 
Ou bien :gcc othello.c SDLfonction.c logique_jeu.c fonction_Tritement_fichier.c -o bin\prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
Il existe le jeu en format .exe dans le dossier othello est nome Othello.exe 
