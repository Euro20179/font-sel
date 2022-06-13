# Font-sel

In my opinion there are not a lot of great font preview tools out there, so I made one mainly just for myself

---

It uses a deprecated function `gtk_widget_override_font` so hopefully it doesn't break too soon.

---

# Building

## Dependencies

`gtk 3`

## Build

```sh
sh ./build
```


---

Don't set the font size too big or you'll probably regret it lol

# Configuration

* The really only thing you can do is style this. A good way to do that is to use `~/.config/gtk-3.0/gtk.css`
* selectors:
    * `#Font-Sel-Window` The window
    * `#font-label` The text that previews the font
    * use `GTK_DEBUG=interactive font-sel` to find more.
