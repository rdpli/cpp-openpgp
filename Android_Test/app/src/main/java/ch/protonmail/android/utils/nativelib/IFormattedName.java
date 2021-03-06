// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

package ch.protonmail.android.utils.nativelib;

import java.util.concurrent.atomic.AtomicBoolean;
import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

/**ezvcard part */
public abstract class IFormattedName {
    @Nonnull
    public abstract String getLanguage();

    public abstract void setLanguage(@Nonnull String language);

    @Nonnull
    public abstract String getParameter(@Nonnull String name);

    @Nonnull
    public abstract String getValue();

    @CheckForNull
    public static IFormattedName createInstance(@Nonnull String name)
    {
        return CppProxy.createInstance(name);
    }

    private static final class CppProxy extends IFormattedName
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public String getLanguage()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getLanguage(this.nativeRef);
        }
        private native String native_getLanguage(long _nativeRef);

        @Override
        public void setLanguage(String language)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setLanguage(this.nativeRef, language);
        }
        private native void native_setLanguage(long _nativeRef, String language);

        @Override
        public String getParameter(String name)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getParameter(this.nativeRef, name);
        }
        private native String native_getParameter(long _nativeRef, String name);

        @Override
        public String getValue()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getValue(this.nativeRef);
        }
        private native String native_getValue(long _nativeRef);

        @CheckForNull
        public static native IFormattedName createInstance(@Nonnull String name);
    }
}
