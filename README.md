Move: WASD

Shoot: Arrow keys

For data oriented way of doing this assignment, I've decided to make an ECS. With keeping all the data in a continuous memory makes them more efficient to process without jumping around heap. Iterating data would be more eaiser and independent to do. For example rendering system only process those entities with rendering component and transform component attached to them instead of looping through all the entity.

At first try of making an ECS, I managed to make an ECS like system in a object-oriented way, where I have all the component classes and associated functions with them. Later I looked up many ECS implementations and eventually it became like this. It took me a lot of time to have this ECS so I don't really have enough time to play around the gameplay, which is why the collision detection is a bit wanky. But it is really fun and enjoyable to play with a system that made by yourself.

I have learned a lot from this project and would love to explore more. Thanks for the opportunity. 
