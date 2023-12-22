# RSA

Défini en 1977 par Ronald Rivest, Adi Shamir et Leonard Adleman, le système de chiffrement RSA utilise les propriétés des nombre premiers et l’arithmétique pour chiffrer des données. Le déroulement de l’algorithme est comme suit :

 - Génération aléatoire de deux nombres premiers p et q (préférablement très grands).
 - Calcul des valeurs n = p * q ; φ(n)=(q-1)* (p-1)
 - Génération de e tel qu’il soit premier avec phi de n,  et inférieur. 
 - Calcul de d l’entier naturel inverse de e par la multiplication modulo φ(n).
 - On a donc la clé publique (n, e) et la clé privée (n, d).
 - Soit M le message, et C le message chiffré on a : 
	C≡M^ⅇ [n]
	M≡C^d [n]

## Les applications de RSA :

 * __Echange de clés__
	RSA est de moins en moins utilisé pour le chiffrement de gros paquets de données. Cependant, il est souvent utilisé en complément d’un système de chiffrement symétrique. Dans des systèmes comme RSAES, on va transmettre la clé symétrique AES chiffrée avec RSA.
	
 * __Transmission de données__ 
	On utilise encore RSA pour la transmission de données dans le réseau, mais c’est souvent exigé d’utiliser des clés de 3072 bits. Les performances de calcul se verront compromises dès qu’on sera obligés à passer à 4096.

## Cette implémentation

Faite pour une meilleur compréhension de l'algorithme.

## Utilisiation

Fonctions nécessaires au chiffrement se trouvent dans rsa.c

Pour le chiffrement :
	void rsa_c(int* m, int size_m, int e, int n)
	
Pour le dechiffrement :
	void rsa_c_d(int* mc, int size_m, int d, int n)
	
_Exemple d'utilisation dans tests.c_
