
#include  "wolf.h"

void calcul_image(t_graf *graf)
{
int dont_make;
//unsigned int color;
double dirx = graf->dirx;
double diry = graf->diry; ///initialisation du verteur directeur
double planex = graf->Planex, planey = graf->Planey; ///Raycaster la deuxieme version du plan de camera
 
  //double time = 0; ///Temps de la sequence courante
  //double oldTime = 0; ///Temps de l'image precedente
 
//  screen(512, 384, 0, "Raycaster");/// definition des parametres de l'ecran (512x384  avec le Titre "Raycaster")
//  while(1 == 1) /// tant que la fonction done() retourne faux, on ne quitte pas le programme
//{	
  	int x ;
  	x = -1;
  	graf->door_not_far = 0;

	while(x++ < W_W)
    {
	 dont_make = 0; 	

      ///calcul de la position et de l'orientation du rayon
      double cam = 2 * x / (double)(W_W) - 1; ///Coordonner x dans l'espace de la camera
      graf->raypos_x = graf->pos_x;				 ///  Coordonner x de rayon dans l'espace
      graf->raypos_y = graf->pos_y;                 /// Coordonner y de rayon dans l'espace
      graf->r_dir_x = dirx + planex * cam;
      graf->r_dir_y = diry + planey * cam;
      ///Dans quelle case de la carte, nous nous situons au debut
      int map_x = (int)(graf->raypos_x);
      int map_y = (int)(graf->raypos_y);
     // printf("\033[5A\033[Kx: %d\nposx: %f\nPosy: %f\nmapx: %d\nmapy: %d\n", x, graf->pos_x, graf->pos_y, map_x, map_y);
    // printf("%d\nposx: %f\nPosy: %f\nmapx: %d\nmapy: %d\n", x, graf->pos_x, graf->pos_y, map_x, map_y);

      ///Longueur des rayons de la position actuelle au prochain x ou y
      double dist_v; ///Distance entre le joueur et 1e prochain mur vertical
      double dist_h; ///Distance entre le joueur et 1e prochain mur horizontal
 
       ///Longueur des rayons de la position  du x ou y actuel au prochain x ou y
      double inc_x2 = sqrt(1 + (graf->r_dir_y * graf->r_dir_y) / (graf->r_dir_x * graf->r_dir_x)); ///Distance entre deux murs verticaux
      double inc_y2 = sqrt(1 + (graf->r_dir_x * graf->r_dir_x) / (graf->r_dir_y * graf->r_dir_y)); ///Distance entre deux murs horizontaux
    //  double graf->wall_d;
 ///Etape du prochain mouvement
      int inc_x; ///si gauche x=-1, si droite x=+1
      int inc_y; ///si avance y=+1 et si recule y=-1
 
      int touche = 0; ///y a-t-il un mur de detecter?
     // int graf->vertical0; ///est-ce un mur horizontal ou vertical? v = 0 et h = 1
 
      ///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur vertical le plus proche en fonction de la prochaine etape x
      if (graf->r_dir_x < 0) /// Si le rayon est oriente vers la gauche
      {
        inc_x = -1;
        dist_v = (graf->raypos_x - map_x) * inc_x2; ///  On calcule la distance entre joueur et 1e prochain mur vertical
      }
      else ///Si le rayon est oriente vers la droite
      {
        inc_x = 1;
        dist_v = (map_x + 1.0 - graf->raypos_x) * inc_x2; /// On calcule la distance entre joueur et 1e prochain mur vertical
      }
      ///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur horizontal le plus proche en fonction de la prochaine etape y
      if (graf->r_dir_y < 0)
      {
        inc_y = -1;///  On recule
        dist_h = (graf->raypos_y - map_y) * inc_y2;///  On calcule la distance entre le joueur et 1e prochain mur horizontal
      }
      else
      {
        inc_y = 1;///  On avance
        dist_h = (map_y + 1.0 - graf->raypos_y) * inc_y2;/// On calcule la distance entre joueur et 1e prochain mur horizontal
      }
      ///lance de DDA = Digital Differential Analysis (algorithme de detection des murs)
      while (touche == 0) //&& dont_make != 1)
      {
        ///Saute au prochain carre de la map soit vers la  direction x, soit vers la direction y en fonction du mur le plus proche
        if (dist_v < dist_h)
        {
          dist_v += inc_x2;
          map_x += inc_x;
          graf->vertical0 = 0; ///Mur vertical
        }
        else
        {
          dist_h += inc_y2;
          map_y += inc_y;
          graf->vertical0 = 1; ///Mur vertical
        }
        ///Verifier si le rayon a detecte un mur
  	//	printf("salut\n");
  		// if (map_y < 0 || map_x < 0  || map_x > graf->size  || map_y > graf->nb_l) 
  		// 	dont_make = 1;
        if (graf->map[map_y][map_x] > 0 ) 
        	touche = 1;
      }
  //	printf("salut 2 \n");
  	//if (dont_make == 0)
  	//{	
      	///Calcul de la distance projetee sur la direction de la camera (La distance oblique donnera un effet fisheye !)
      if (graf->vertical0 == 0)
      graf->wall_d = ((map_x - graf->raypos_x + (1 - inc_x) / 2) / graf->r_dir_x);
      else
      graf->wall_d = ((map_y - graf->raypos_y + (1 - inc_y) / 2) / graf->r_dir_y);

  		if(graf->map[map_y][map_x] == 9  && graf->wall_d < 2)
  			{
  				//printf("dist  = %f\n",graf->wall_d);
  				graf->door_not_far = 1;
  				graf->door_y = map_y;
  				graf->door_x = map_x;
  			}
      ///Calculer la hauteur de la ligne appelee a l'ecran
      int hauteurMur = ((int)(W_H / graf->wall_d));
 
      ///Calculer le plus bas et le plus eleve des pixels a remplir dans la bande actuelle
      int draw_start = -hauteurMur / 2 + W_H / 2;
      if(draw_start < 0)draw_start = 0;
      int draw_end = hauteurMur / 2 + W_H / 2;
      if(draw_end >= W_H)draw_end = W_H - 1;
 
      /// Definition de la couleur des murs
    //  Uint8 colorR;
      //Uint8 colorG;
   //   Uint8 colorB;
      // switch(graf->map[map_y][map_x])
      // {// 0x10000 * red + 0x100 * green + blue
      //   case 1:  color = 0x10000 * 255 + 0x100 * 0 + 0;  break; ///rouge
        // case 2:	 color = 0x10000 * 0 + 0x100 * 255 + 0;  break; ///vert
        // case 3:  color = 0x10000 * 0 + 0x100 * 0 + 255;   break; ///bleu
        // case 4:  color = 0x10000 * 255 + 0x100 * 255 + 255;  break; ///blanc
        // default: color = 0x10000 * 255 + 0x100 * 255 + 0; break; ///jaune
      //}

       if (graf->map[map_y][map_x] == 1)
      {
      		//dont_make = 1;
      		ft_basic_wall(map_x,map_y,graf);//= 0x10000 * 255 + 0x100 * 0 + 0;  break; ///rouge
      		draw_wall(x, draw_start, draw_end,graf);
      }
      else
      {
      	graf->map_value = graf->map[map_y][map_x];
     	ft_texture_maker(graf);
		draw_wall_texture(x, draw_start,draw_end,graf);

      //	break;
      }
      // if (graf->map[map_y][map_x] == 1)
      // {
      // 		dont_make = 1;
      // 		color = ft_basic_wall(map_x,map_y,dirx,diry,graf->vertical0);//= 0x10000 * 255 + 0x100 * 0 + 0;  break; ///rouge
      // }
      // if (dont_make == 0) 
      // 	printf("wtf value %d mapx = %d mapy = %d \n",graf->map[map_y][map_x],map_x,map_y);
      // draw_wall(x, draw_start, draw_end, color);
 
      // ///On applique une couleur differente pour les murs verticaux (sinon on ne "ressent pas" la 3D)
       // if (graf->vertical0 == 1)
       // {
       //     color /= 2;
       //     color /= 2;
       //     color /= 2;
       // }
      ///Dessine les pixels de l'ecran par ligne verticale
      //draw_wall(x, draw_start, draw_end, color);
	//}
     // printf("G PRINT\n");
    } ///Fin de la boucle for
// }

}
