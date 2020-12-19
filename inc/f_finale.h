#if !defined(__F_FINALE_H__)
#define __F_FINALE_H__

//
// FINALE
//

// Called by main loop.
dboolean F_Responder(event_t *ev);

// Called by main loop.
void F_Ticker(void);

// Called by main loop.
void F_Drawer(void);

void F_StartFinale(void);

#endif
