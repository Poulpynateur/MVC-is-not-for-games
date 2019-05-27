# SFML Game-Engine

Game template based on the [SFML](https://www.sfml-dev.org/) library.

**Update are constant, the frame rate is fixed :**

```
	while (true)
	{
	  double start = getCurrentTime();
	  processInput();
	  update();
	  render();
	
	  sleep(start + MS_PER_FRAME - getCurrentTime());
	}
```
