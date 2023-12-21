# calculator
Codename Calculator. 
Essentially a random project proving that code drives architecture. 
As I solve problems and want to add more to my application, the architecture changes.
This app started as a simple CPP calculator and evolves to more complex and useful code.
A completely random and hilarious conconction of GUI, OOP, graphics, and cool CPP code

# Qt
This project uses Qt for the GUI.
"Qt is a cross-platform application framework that is widely used for developing application software that can be run on various software and hardware platforms with little or no change in the underlying codebase, while still being a native application with native capabilities and speed. Qt is currently being developed by The Qt Company, a publicly listed company, and the Qt Project under open-source governance, involving individual developers and organizations working to advance Qt. Qt is available with both commercial and open-source GPL 2.0, GPL 3.0, and LGPL 3.0 licenses." - Wikipedia

# TODO
- **get the play button working**
- **get the image for the moving bear**
- **get the berrie image that the bear will go after**
- **Integrate the game board with original meadow**
## Steps:
1. Set Up the Basic Application Structure
   Create a new Qt project.
   Set up the main window or widget to host the game.
2. Design and Implement the Game Board
   Create a custom widget (subclass QWidget or QGraphicsView) for the game board.
   Implement the paint event to draw the background (meadow image).
3. Create Game Elements (Bear and Blueberry)
   Design or select images for the bear and blueberry.
   Implement custom graphics items or widgets to represent the bear and blueberry.
4. Implement Bear Movement
   Override the keyPressEvent in the game board to respond to arrow keys.
   Implement logic to move the bear within the game board's boundaries.
5. Implement Random Placement of the Blueberry
   Create a function to randomly position the blueberry within the game board.
6. Implement Collision Detection
   Develop a method to detect collisions between the bear and the blueberry.
7. Add Sound Effects
   Find or create a chomping sound effect.
   Use QSoundEffect to play the sound upon collision.
8. Implement Score Keeping
   Create a variable to keep track of the score.
   Display the score on the game board using a QLabel or similar widget.
9. Handle Game Logic and Updates
   Set up a game loop using a timer (QTimer) to periodically update the game state.
   Implement logic to update the position of the bear and check for collisions in each game loop iteration.
   Update the score and reposition the blueberry after a collision.
10. Polish and Finalize the Game
    Add start, pause, and end game functionalities.
    Implement a game over condition and display.
    Refine the user interface, add instructions, and polish the overall appearance.
    Test the game thoroughly to ensure it works as expected and fix any bugs.
11. Optimization and Enhancements
    Optimize the game for performance and responsiveness.
    Consider adding additional features like levels, timers, or different types of obstacles.
12. Documentation and Packaging
    Write documentation explaining how to play the game and any other important information.
    Package the game for distribution (if desired).