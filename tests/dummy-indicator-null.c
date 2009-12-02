
#include <glib.h>
#include <glib-object.h>

#include "libindicator/indicator.h"
#include "libindicator/indicator-object.h"

#define DUMMY_INDICATOR_NULL_TYPE            (dummy_indicator_null_get_type ())
#define DUMMY_INDICATOR_NULL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DUMMY_INDICATOR_NULL_TYPE, DummyIndicatorNull))
#define DUMMY_INDICATOR_NULL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), DUMMY_INDICATOR_NULL_TYPE, DummyIndicatorNullClass))
#define IS_DUMMY_INDICATOR_NULL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DUMMY_INDICATOR_NULL_TYPE))
#define IS_DUMMY_INDICATOR_NULL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DUMMY_INDICATOR_NULL_TYPE))
#define DUMMY_INDICATOR_NULL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), DUMMY_INDICATOR_NULL_TYPE, DummyIndicatorNullClass))

typedef struct _DummyIndicatorNull      DummyIndicatorNull;
typedef struct _DummyIndicatorNullClass DummyIndicatorNullClass;

struct _DummyIndicatorNullClass {
	IndicatorObjectClass parent_class;
};

struct _DummyIndicatorNull {
	IndicatorObject parent;
};

GType dummy_indicator_null_get_type (void);

INDICATOR_SET_VERSION
INDICATOR_SET_TYPE(DUMMY_INDICATOR_NULL_TYPE)


GtkLabel *
get_label (IndicatorObject * io)
{
	return NULL;
}

GtkImage *
get_icon (IndicatorObject * io)
{
	return NULL;
}

GtkMenu *
get_menu (IndicatorObject * io)
{
	return NULL;
}

static void dummy_indicator_null_class_init (DummyIndicatorNullClass *klass);
static void dummy_indicator_null_init       (DummyIndicatorNull *self);
static void dummy_indicator_null_dispose    (GObject *object);
static void dummy_indicator_null_finalize   (GObject *object);

G_DEFINE_TYPE (DummyIndicatorNull, dummy_indicator_null, INDICATOR_OBJECT_TYPE);

static void
dummy_indicator_null_class_init (DummyIndicatorNullClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->dispose = dummy_indicator_null_dispose;
	object_class->finalize = dummy_indicator_null_finalize;

	IndicatorObjectClass * io_class = INDICATOR_OBJECT_CLASS(klass);

	io_class->get_label = get_label;
	io_class->get_image = get_icon;
	io_class->get_menu = get_menu;

	return;
}

static void
dummy_indicator_null_init (DummyIndicatorNull *self)
{

	return;
}

static void
dummy_indicator_null_dispose (GObject *object)
{

	G_OBJECT_CLASS (dummy_indicator_null_parent_class)->dispose (object);
	return;
}

static void
dummy_indicator_null_finalize (GObject *object)
{

	G_OBJECT_CLASS (dummy_indicator_null_parent_class)->finalize (object);
	return;
}