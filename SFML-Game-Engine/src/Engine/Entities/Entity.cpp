#include "Entity.h"

Entity::Entity()
: dismised(false)
{}

/**** GETTERS and SETTERS ****/
void Entity::setDismised() {
	dismised = true;
}
bool Entity::isDismised() {
	return dismised;
}