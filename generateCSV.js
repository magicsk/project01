var names = ["Fredricka", "Stacks", "Mack", "Vogt", "Rhett", "Devalle", "Jami", "Wischmeier", "Rema", "Petrus", "Afton", "Lindquist", "Alphonso", "Flanary", "Jacinto", "Mcgeehan", "Terra", "Russom", "Eddy", "Boothe", "Yee", "Voisin", "Eilene", "Auslander", "Tora", "Cramer", "Cyrstal", "Almazan", "Essie", "Shurtliff", "Wilford", "Faw", "Frances", "Edney", "Carmelina", "Schwalm", "Tonette", "Labrador", "Emerald", "Leff", "Tristan", "Mcnair", "Camille", "Legault", "Dewitt", "Bowyer", "Lissa", "Barcomb", "Santos", "Timpson", "Loretta", "Wenger", "Margarett", "Pfister", "Abby", "Spencer", "Brooks", "Perera", "Danille", "Delnero", "Mazie", "Dominick", "Charise", "Hoey", "Alice", "Slater", "Matilda", "Bengtson", "Peggie", "Fasching", "Carleen", "Gomes", "Shawn", "Huss", "Iris", "Hutton", "Carlita", "Cambra", "Karen", "Hanlon", "Jesse", "Wygant", "Marcus", "Luman", "Major", "Nicola", "Maynard", "Crooks", "Michele", "Winebrenner", "Felisa", "Willard", "Monica", "Murtagh", "Norris", "Killingsworth", "Nannette", "Hannaford", "Minta", "Amburn"];
var brands = ["Mazda", "Porsche", "Alpine", "Ferrari", "McLaren", "Mercedes", "BMW", "Nissan", "Lamborghini", "Bugatti", "Abarth", "Audi", "Ford", "Chevrolet", "Koenigsegg"];

for (i = 0; i < 100; i++) {
    var name = Math.floor((Math.random() * 100));
    var surname = Math.floor((Math.random() * 100));
    
    var gender = name % 2 ? "m" : "f";
    var year = Math.floor((Math.random() * 1000) + 1000);

    var brand = Math.floor((Math.random() * 15));
    
    var r1 = Math.floor((Math.random() * 50000)+50000)/1000;
    var r2 = Math.floor((Math.random() * 50000)+50000)/1000;
    var r3 = Math.floor((Math.random() * 50000)+50000)/1000;
    var r4 = Math.floor((Math.random() * 50000)+50000)/1000;
    var r5 = Math.floor((Math.random() * 50000)+50000)/1000;

    var out = `${names[name]} ${names[surname]};${gender};${year};${brands[brand]};${r1};${r2};${r3};${r4};${r5}`;
    console.log(out);
}