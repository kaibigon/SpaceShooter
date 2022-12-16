Hi, David

I did this assignment on Xcode cause I don't have PC around me weeks ago.

I'm migrating the project to visual studio under branch vs2019, now it's Friday, Dec 16 afternoon and I actually couldn't make it done today. So I will attach a video of running the project on Mac instead and try to migrate it later. Just in case if you're viewing this assignment and I haven't have it done, you can see the video that I attach. Sorry for the inconvenience.

### Data oriented design

Under include folder, it contains all the local include files.

- include
  - **Components**
    - componnet files
  - **ECS**
    - ecs core files
  - **Systems**
    - ecs system files

At first, I built the ECS in the wrong way, which I made component into a class and blinding associated function that component needs (like if I'm gonna have a movement component then it's a movement class with move() function in it ). I realized it's still a object-oriented so I totally remade it as below:

### Entity

The entity is just a number, with an entity manager take in charge of creating/destroying (adding/removing) them from an entity array.

### Component

The **component** itself is a structure, for each **component** type, there is a components array associated with it.

The **components array **holds whether an entity is attached with a specific component type.

Let's say we have some **entities: 0, 2, 4, 6. 8** with component named **movement component** attached to them

a component array with type <MovementComponent>is created, holding content of {0, 2, 4, 6, 8}. 

To see what are the components an entity is holding, we have a signature for this. For example, an entity can hold max 8 components. Now we have an entity:0, with 4 components (movement-0, render-2, collision-4, transform-6) attach to it. The signature for entity 0 wil be like : {01010101}

Since the whole ECS system's point is to keey data in a continuous memory, we define all the data structure above as array.

### System

Once we have entity and component, we need system for implementing the functionality.

For each system, it has the required component type, that is it will only look for the entities that has those components. That is why we need component signature for each entity. By doing this, we can easily do bit operation ( **entitySignature & systemSignature == systemSignature**) to filter out the entities we want.

### Take away

Combining all the stuffs we got a basic ECS. I used it to implement simple player movement, shooting and collision detection in this project. But a lot of code that I wrote are very lack of design and I'm a C++ noob. I will probably continue to do a bit more in this project and study bevy engine in Rust since I found it a interesting language.

I have learned a lot from this project. Thanks for the opportunity.