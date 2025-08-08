# Project Notes

## General structure
> Entrypoint -> create Scene Manager

> SM -> holds Scene methods and info (Scene list & Interaction between them)

> SM -> create Sample Scene and set it as the Active Scene

> AS -> Start, Update loop, Renderer, Object list

> AS.Update -> calls each object's components own update each tick (Start does the same when the scene instantiated object is initialised)

> AS.Renderer -> handles assembly of graphics based on each individual object (if invisible then null) analogously to update

