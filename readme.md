Faire du troc sous forme de blockchain sans aucune monnaie.

# Assignation d'un objet réel dans la blockchain

    Chaque individu ayant une identité sur la blockchain peut prendre une photo de l'objet réel et dire à tout le monde : ça c'est à moi. Ensuite il reçoit une signature (sha256) et dans la blockchain : l'individu possède la signature et donc l'objet dans la vie réelle.

# Échange d'un objet réel dans la blockchain en instantané

    Chaque individu ayant renseigné son objet peut l'échanger contre un autre. Pour cela, il fait une proposition sur la blockchain disant : individu veut échanger signature contre autre signature d'un autre individu. La demande est faite, les vendeurs se contactent par mail, puis les deux vendeurs doivent valider que l'échange a bien été effectué (sauf si les deux veulent finalement le valider même s'ils l'ont pas reçu) et ainsi, les signatures sont échangées.

# Échange d'un objet réel dans la blockchain en différé

    Un individu A veut un objet. Mais il n'a pas d'objets à échanger qui conviennent à l'individu B. Dans ce cas-là, la monnaie virtuelle entre en jeu. L'individu B possède n pièces et l'individu A m pièces. Si m > 0 alors l'échange va se faire et l'individu A va posséder n - 1 pièces et l'individu B m + 1. Cette monnaie permet donc de faire des échanges en différé. La demande de l'échange va se faire, l'individu B l'envoie physiquement et valide de son côté. À ce stade, il faut attendre que l'individu A valide la réception mais même en l'ayant reçu, il peut ne pas l'avouer. Pour éviter cela, au moment de la demande, m est mis à 0 tant que la réception n'est pas accusée. Si B le reçoit, il le valide et m revient à m - 1 mais s'il ne le reçoit pas, il peut l'indiquer et dans ce cas là, l'échange est annulé.

# Blockchain et décentralisation

    Le réseau fonctionnant sous la forme d'une blockchain, le système est donc décentralisé. Les possessions des objets deviennent des "vérités générales" pour le réseau. Si des serveurs tombent ou subissent des attaques, ils sont mis à l'écart de celui-ci. 
