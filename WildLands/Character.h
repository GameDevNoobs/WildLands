#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
	struct PrimaryStats {
		double strenght; 
		double perception;
		double endurance;
		double charisma;
		double agility;
		double intelligence;
		double luck;
	}PRIMARYSTATS;

	struct DetivedStats {
		double hp;
		double armor_class;
		double action_points;
		double carry_weight;
		double melee_damage;
		double damage_resistance;
		double poison_resistance;
		double sequence;
		double healing_rate;
		double critical_chance;
	}DEVIDEDSTATS;


};

#endif
