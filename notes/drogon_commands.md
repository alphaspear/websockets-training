# Drogon

`drogon_ctl == dg_ctl`

## New Project

```bash
drogon_ctl create project <project-name>
```

## Building

```bash
cd build
cmake ..
make
```

## Simple `index.html`

```bash
echo '<h1>Hello Drogon!</h1>' >> index.html
```

---

## New controller

```bash
cd controllers
drogon_ctl create controller [-s] HelloCtrl
```

`-h` for a HTTP controller & `-w` for a WebSocket controller.
