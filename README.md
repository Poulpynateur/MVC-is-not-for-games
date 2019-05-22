# SFML Game-Engine

Game template based on the [SFML](https://www.sfml-dev.org/) library.

**The main loop work with the [Sequencing Patterns](https://gameprogrammingpatterns.com/game-loop.html) :**

```
double previous = getCurrentTime();
double lag = 0.0;
while (true)
{
  double current = getCurrentTime();
  double elapsed = current - previous;
  previous = current;
  lag += elapsed;

  processInput();

  while (lag >= MS_PER_UPDATE)
  {
    update();
    lag -= MS_PER_UPDATE;
  }

  render();
}
```